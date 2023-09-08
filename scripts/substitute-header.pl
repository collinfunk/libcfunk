#!/usr/bin/env perl

use strict;
use warnings;

my $cache_file = '';
my $template_file = '';
my $output_file = '';

# Defines taken from the cache file.
my %defines;

sub emit_usage ($)
{
  my ($exit_code) = @_;

  print <<EOF
  This file is run internally at the end of the build process by CMake.
  It should not be used manually. It is similar to CMake's `configure_file ()'
  except it treats missing variables and empty strings as "0". This allows
  them to be used with the C preprocessor.

  It is invoked like so in `libcfunk-final.cmake':
    substitute-header.pl cache-file template-file output-file
EOF
    ;

  exit ($exit_code);
}

# Read all variables from the CMake cache.
sub get_cache_vars ($)
{
  my ($file_name) = @_;
  my $file_handler;

  open ($file_handler, "<", $file_name) or
    die "Could not open cache file `$file_name': $!.\n";

  foreach (<$file_handler>)
    {
      chomp;
      if ($_ =~ /(\w+):(?:\w+)=(?:(\w+))?/)
        {
          my $name = $1;
          my $value = defined ($2) ? $2 : "0";
          $defines{$name} = $value;
        }
    }

  close ($file_handler);
}

# Generate the file with the CMake cache variables.
# If a variable is not in the cache or if it is set to an empty string,
# it is replaced with a "0". This allows it to be used with the C preprocessor.
sub generate_file ($$)
{
  my ($src_filename, $dest_filename) = @_;
  my $src_handler;
  my $dest_handler;

  open ($src_handler, "<", $src_filename) or
    die "Could not open template file `$src_filename': $!.\n";
  open ($dest_handler, ">", $dest_filename) or
    die "Could not open destination file `$dest_filename': $!.\n";

  foreach (<$src_handler>)
    {
      my $line = "$_";
      if ($line =~ /@(\w+)@/)
        {
          my $replacement;
          if (exists ($defines{$1}))
            {
              $replacement = $defines{$1};
            }
          else
            {
              $replacement = "0";
            }
          $line =~ s/\@$1\@/$replacement/g;
        }
      print ($dest_handler "$line");
    }

  close ($src_handler);
  close ($dest_handler);
}

if (scalar @ARGV >= 1)
  {
    if ($ARGV[0] eq "-h" || $ARGV[0] eq "--help")
      {
        emit_usage (0);
      }
  }

if (scalar @ARGV < 3)
  {
    emit_usage (1);
  }

$cache_file = $ARGV[0];
$template_file = $ARGV[1];
$output_file = $ARGV[2];

die ("Cache file `$cache_file' does not exist.\n") if
  ! -f $cache_file ;

get_cache_vars ($cache_file);
generate_file ($template_file, $output_file);
