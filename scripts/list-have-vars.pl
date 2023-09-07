#!/usr/bin/env perl

use strict;
use warnings;

my %defines;

sub scan_file ($)
{
  my ($file_name) = @_;
  my $file_handler;

  open ($file_handler, "<", $file_name) or
    die "Could not open $_: $!\n";

  foreach (<$file_handler>)
    {
      chomp;
      if ($_ =~ /(HAVE_(\w+))/)
        {
          $defines{$1}++;
        }
    }

  close ($file_handler);
}

foreach (@ARGV)
  {
    scan_file ($_);
  }

foreach (sort keys %defines)
  {
    print ("$_\n");
  }
