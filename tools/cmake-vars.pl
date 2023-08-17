#!/usr/bin/env perl

use strict;
use warnings;
use File::Basename;
use File::Spec;
use Set::Scalar;

my $THIS_FILE = File::Spec->rel2abs (File::Spec->curdir (), __FILE__);
my $THIS_DIR = dirname ($THIS_FILE);

my $header_variables = Set::Scalar->new;
my $symbol_variables = Set::Scalar->new;


sub usage ($)
{
  my ($exit_code) = @_;
  print <<EOF;
Usage: $THIS_FILE filename ...
EOF

  exit ($exit_code) if $exit_code != 0;
}

my $set_string_per_line_callback = sub {join ("\n", sort (shift->elements))};

$symbol_variables->as_string_callback ($set_string_per_line_callback);
$header_variables->as_string_callback ($set_string_per_line_callback);

sub load_cmake_variables(@)
{
  my (@filenames) = @_;

  my $check_include_regexp = qr/\s*check_include_files?\s*
                                \(\s*\"?(?:.+?)\"?\s+(.+?)\)/x;
  my $check_symbol_regexp = qr/\s*check_symbol_exists\s*
                               \(\s*(?:.+?)\s+\"?(?:.+?)\"?
                               \s+(.+?)\)/x;

  foreach (@filenames)
    {
      open (my $fh, "<", "$_") or die "Failed to open $_: $!\n";

      while (<$fh>)
        {
          chomp;

          if ($_ =~ $check_include_regexp)
            {
              $header_variables->insert($1);
            }
          elsif ($_ =~ $check_symbol_regexp)
            {
              $symbol_variables->insert($1);
            }
        }

      close ($fh);
    }
}

sub set_to_sorted_list($)
{
  my ($varset) = @_;
  my @varlist = ();

  while (defined (my $variable = $varset->each))
    {
      push (@varlist, $variable . "\n");
    }

  return sort (@varlist);
}

if (scalar (@ARGV) < 1)
  {
    usage (1);
  }

load_cmake_variables (@ARGV);

my @headers = set_to_sorted_list ($header_variables);
my @symbols = set_to_sorted_list ($symbol_variables);

if (scalar (@headers) > 0)
  {
    print ("#cmakedefine01 " . join ("#cmakedefine01 ", @headers) . "\n");
  }

if (scalar (@symbols) > 0)
  {
    print ("#cmakedefine01 " . join ("#cmakedefine01 ", @symbols) . "\n");
  }
