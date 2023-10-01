#!/usr/bin/env perl

use strict;
use warnings;
use Getopt::Long;
use File::Spec;
use File::Basename;

my $program_name = basename (__FILE__);
my $config_header = "config.h";
my @source_list = ();
my %unique_sources;
my $return_val = 1;

sub usage ($)
{
  my ($exit_code) = @_;

  print <<EOF;
$program_name [OPTIONS] files
Check that a configured header is the first thing included in a C source file.
This is nessecary if the source file or any subsequent includes rely on macros
which are defined by the build system.

Options:
  --config-header
  --sources

EOF
  ;

  exit ($exit_code);
}

sub parse_arguments ()
{
  GetOptions ('config-header=s' => \$config_header,
              'sources=s' => \@source_list,
              'help' => sub  { usage (0) });

  @source_list = split (/,/, join (',', @source_list));

  foreach (@ARGV)
    {
      push (@source_list, $_);
    }
}

sub verify_config_h_included ($)
{
  my ($file_name) = @_;
  my $file_handler;
  my $saw_include = 0;

  open ($file_handler, "<", $file_name) or
    die "Failed to open file: $file_name: $!.\n";

  foreach (<$file_handler>)
    {
      if ($_ =~ /^\s*#\s*include\s+["<](.+?)[">]/)
        {
          $saw_include = 1;
          if ($1 ne $config_header)
            {
              print <<EOF
The first include of '$file_name' is $1. Include $config_header first.
EOF
                ;
            }
          last;
        }
    }

  if ($saw_include == 0)
    {
      print <<EOF
The file '$file_name' includes no files. Include $config_header.
EOF
        ;
    }

  close ($file_handler);
}

parse_arguments ();

foreach (@source_list)
  {
    if (! -f "$_")
      {
        print ("File does not exist: $_.\n");
        $return_val = 1;
      }
    else
      {
        $return_val = 0;
        if (!exists ($unique_sources{$_}))
          {
            $unique_sources{$_} = 1;
          }
        else
          {
            print ("Ignoring duplicate file: $_\n");
          }
      }
  }

foreach (sort keys %unique_sources)
  {
    verify_config_h_included ($_)
  }

exit ($return_val);
