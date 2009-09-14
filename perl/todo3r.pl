#!/usr/bin/perl -w

# Perl script that scans each directory and print out lines with TODO
# format:
# filename:line number: TODO Work
#

sub look_for_TODO
{
 my $filename = $_[0] ;
 my $basename ;
 $basename = `basename $filename` ;
 chomp $basename ;
 open(TO_READ,"<$filename") ;
 my $flag = 0 ;
 while(<TO_READ>)
 {
  if( $flag )
  {
   print "$basename:$.: $_" ;
   $flag = 0 ;
  }
  
  if( $_ =~ m/TODO/)
  {
   $flag = 1 ;
  }

 }

}


sub main 
{
 if( $#ARGV != 0 )
 {
  print "Usage: scan_files directory_name \n" ;
  exit 1 ;
 }

 my $dir_name = $ARGV[0] ;
 @files = <$dir_name/*> ;
 print "Here is TODO list for you:\n" ;

 foreach $file ( @files )
 {
  look_for_TODO($file) ;
 }
}

main ;
