#!/usr/bin/env perl

use strict;
use warnings;
use File::Basename;
use File::Spec;

my $THIS_FILE = File::Spec->rel2abs (File::Spec->curdir (), __FILE__);
my $THIS_DIR = dirname ($THIS_FILE);

sub usage ($)
{
  my ($exit_code) = @_;
  print <<EOF;
Usage: $THIS_FILE filename ...
EOF

  exit ($exit_code) if $exit_code != 0;
}

sub print_includes (@)
{
  my (@filenames) = @_;

  foreach (@filenames)
    {
      open (my $fh, "<", "$_") or die "Failed to open $_: $!\n";

      my $fmt_name = basename($_);
      my @local_includes = ();
      my @system_includes = ();

      while (<$fh>)
        {
          chomp;
          if ($_ =~ /\s*#\s*include\s*\"(.+?)\"/)
            {
              push (@local_includes, $1);
            }
          elsif ($_ =~ /\s*#\s*include\s*<(.+?)>/)
            {
              push (@system_includes, $1)
            }
        }

      my $local_count = scalar (@local_includes);
      my $system_count = scalar (@system_includes);

      if ($local_count > 0 || $system_count > 0)
        {
          print ("File: $fmt_name\n");

          if ($local_count > 0)
            {
              print ("Local includes:\n");
              print (join ("\n", @local_includes) . "\n\n");
            }

          if ($system_count > 0)
            {
              print ("System includes:\n");
              print (join ("\n", @system_includes) . "\n\n");
            }
        }

      close ($fh);
    }
}

if (scalar (@ARGV) < 1)
  {
    usage (1);
  }

print_includes (@ARGV);
