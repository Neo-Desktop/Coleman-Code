#!/usr/bin/env perl
################################################
#           Name: Amrit Panesar
# Student Number: 77260
#        Program: 03
################################################

use strict;
use warnings;
use Data::Dumper qw(Dumper);

use DBI;
use DBD::mysql;
my $dsn = "DBI:mysql:database=ad77260";
my $dbh = DBI->connect($dsn, "ad77260", "90dd0e54");
my $drh = DBI->install_driver("mysql");

use CGI;
use CGI::Carp qw(fatalsToBrowser warningsToBrowser);
my $cgi = new CGI();
my $file = $cgi->param('file');

my %config = do './constraints.pl';

print $config{"head"};


if (!defined($ENV{"QUERY_STRING"})) {
	$ENV{"QUERY_STRING"} = ""; # for debugging purposes
}
if ($ENV{"QUERY_STRING"} eq "env") {
	print "<h1>Linux Sandbox Enviroment</h1>";
	print "<pre>";
	print "\$0 = $0\n";
	print "time() = ".time()."\n";
	foreach my $key (sort keys(%ENV)) {
		print "$key = $ENV{$key}\n";
	}
	print "</pre>";
} elsif ($ENV{"QUERY_STRING"} eq "form") {
	if ($ENV{"REQUEST_METHOD"} eq "POST" || $ENV{"REQUEST_METHOD"} eq "PUT") {
		my $tempfiletime = time();
		my $tempfile = $config{"uploads_directory"}.$tempfiletime;
		print "<pre>";
		if ($file ne "") {
			my $fh = $cgi->upload('file');

			if (! open(OUTFILE, ">", $tempfile) ) {
				print "Can't open ". $tempfile ." for writing - $!";
			} else {
				print "Saving the file to $tempfile\n";
				my $bytes = 0;
				my $total = 0;
				my $hold = "";
				binmode($fh);
				while ($bytes = read($fh, $hold, 1024)) {
					print OUTFILE $hold;
					$total += $bytes;
				}
				print "Saved $total bytes of file $file to $tempfile successfully.\n";
			}
		}
		#print "\n";
		#print "\$0 = $0\n";
		#print $cgi->Dump;
		
		my $sth = $dbh->prepare($config{'sql_insert'}) or die $dbh->errstr;

		my @sports = $cgi->param("favoritesport");
		my $sportsList = join("|", @sports);

		my @cities = $cgi->param("citiesToVisit");
		my $citiesList = join("|", @cities);

		$dbh->{RaiseError} = 1;  
		$sth->bind_param(1, "".$cgi->param("firstname"), {});
		$sth->bind_param(2, "".$cgi->param("lastname"), {});
		$sth->bind_param(3, "".$cgi->param("address1"), {});
		$sth->bind_param(4, "".$cgi->param("address2"), {});
		$sth->bind_param(5, "".$cgi->param("city"), {});
		$sth->bind_param(6, "".$cgi->param("state"), {});
		$sth->bind_param(7, "".$cgi->param("email"), {});
		$sth->bind_param(8, "".$cgi->param("password"), {});
		$sth->bind_param(9, "".$cgi->param("colors"), {});
		$sth->bind_param(10, "".$sportsList, {});
		$sth->bind_param(11, "".$citiesList, {});
		$sth->bind_param(12, "".$cgi->param("file"), {});
		$sth->bind_param(13, "".$tempfiletime, {});
		$sth->execute;

		print $dbh->{'mysql_error'}."\n";
		$sth->finish;

		#print "\n\n\n\n";
		print "Redirecting you to output table in 5 seconds.\n";
		print "</pre>";
		print $config{"meta_redirect"};
	} elsif ($ENV{"REQUEST_METHOD"} eq "GET") {
		print $config{"form"};
	}
} elsif ($ENV{"QUERY_STRING"} eq "view") {
		my $sth = $dbh->prepare($config{'sql_select'});
		$sth->execute;
		print $config{"table_header"};
    	do {
		    while (my @row = $sth->fetchrow_array())  {
		    	print "\t\t<tr>";
	      		foreach (0..$#row) {
	      			my $hold = "";
	      			if ($_ eq "7" || $_ eq "8") {
	      				$hold = join(", ", split(/\|/, $row[$_]));
	      			} elsif ($_ eq "10") {
	      				if ($row["9"] ne "") {
	      					my $hf = $config{"uploads_directory"}.$row[$_];
	      					my $output = `file --mime-type -b $hf`;
      						if ($output =~ /image/) {
								$hold = "<img height=\"100\" width=\"100\" src=\"uploads/". $row[$_] ."\">";
      						} else {
      							$hold = "<a href=\"uploads/". $row[$_] ."\">Download</a>";
      						}
	      				} else {
	      					$hold = "No File Uploaded";
	      				}
	      			}
	      			else {
	      				$hold = $row[$_];
	      			}
	        		print "\t\t\t<td>".$hold."</td>";
	      		}
	      		print "\t\t</tr>";
	    	}
    	} until !($sth->more_results);
    	$sth->finish;
		print $config{"table_footer"};
} else {
	print $config{"default_message"}
}


print $config{"foot"};
