#!/usr/bin/env perl
################################################
#           Name: Amrit Panesar
# Student Number: 77260
#        Program: 02
################################################

use Win32::Console::ANSI;
use Term::ANSIColor;
use Term::ReadKey;
use Data::Dumper qw(Dumper);
use strict;
#use warnings;

$\ = "\n";
$| = 1;

#variables
my ($input, $choice, $temp, $hold);
my $debug = 0;
my @states = ("Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming");
my %callsigns = ();
my %callstates = ();

############################lets begin##########
system("cls");
system("color 1e");
&doInit;
&doMenu();
system("cls");
system("color 07");
print "\n"x5;
&again();
print "\n\nThanks for playing!";
exit;

##########################begin subroutines#####
sub _getKey
{
	my $key = undef;
	while (not defined($key = ReadKey(-1))) { };
	print $key;
	return $key;
}
sub _anyKey
{
	print "\n";
	print "Press any key to continue...";
	_getKey();
}

sub again
{
	printf "Run again?\n[Y/n] :";
	my $key = undef;
	while(1) {
		$key = lc(_getKey());
		#print ord($key);
		if ($key eq 'y' || $key eq 'n' || ord($key) == 13) {
			last;
		}
	}
	if ($key eq 'y' || ord($key) == 13) {
		print "\n"x2;
		system ("pause");
		do __FILE__;
	}
}

sub doInput
{
	my $prompt = shift;
	my $input = "";
	printf(">%s\n: ", $prompt);
	chomp($input = <>);
	print "\n";	
	return $input;
}

sub AUTOLOAD
{
	use vars qw($AUTOLOAD);
	print "Could not find subroutine ".$AUTOLOAD;
	_anyKey();
}

sub doMenuLine
{
	my $line = shift;
	my $spaces = " "x((78 - length($line))/2);
	print "|".$spaces.$line.$spaces."|";
}

sub doMenu
{
	my $input = "";
	while ($input eq "")
	{
		system("cls");
		print "  "."_"x(75);
		print " /"." "x(75)."\\ ";
		if ($debug) {
			doMenuLine("Main menu - debug");
		} else {
			doMenuLine("Main menu");
		}
		doMenuLine("-"x(15));
		doMenuLine("C - Enter a call letter to search      ");
		doMenuLine("S - Enter a state to list stations     ");
		doMenuLine("I - Statistical information            ");
		doMenuLine("-"x(19));
		doMenuLine("Q - Quit                               ");
		print "|"." "x(77)."|";
		print " \\"."_"x(75)."/";
		print $\;
		&stats();
		print $\.$\;
	
		printf "Please enter a menu option: ";
		chomp($input = lc(<>));
		print "\n";
		
		if (defined($input)) {
			if ($input eq 'c') {
				$input = "";
				&callSigns();
				&_anyKey();
			} elsif ($input eq 's') {
				$input = "";
				&stateSearch();
				&_anyKey();
			} elsif ($input eq 'i') {
				$input = "";
				&stats();
				&_anyKey();
			} elsif ($input eq 'q') {
				last;
			} else {
				$input = undef;
				print "Error, please enter a valid menu option: c, s, i, or q";
				_anyKey();
			}
		}
	}
}

sub doInit
{
	open FH, "<", "CallLetters.txt", or die $!;
	while (<FH>) {
		my ($q, $w, $e)	= split(/^(W|K[A-Z]{2,3}(-TV)?(-DT)?)(.+)/, $_);	# should give me callcode in $q, metadata in $w
		my ($e, $r, $t)	= split(/,/, $_, 2);								# gives me last word of city in $e, state name and beyond in $r
		my ($z, $x, $c)	= split(/ /, $r, 3);								# $z and $x should have two words of statename
		my $state 		= join(' ', $z, $x, $c);
		my $stateout	= "";

		foreach (@states) {
			if (index($state, $_) != -1) {
				$stateout = $_;
			}
		}
		my @data= ($stateout, $e);

		$callsigns{$w} = \@data;
		$callstates{$stateout} = $callstates{$stateout} .";". $w;
	}
	close FH;
}

sub stats
{
	print "Total number of call signs loaded: ". keys(%callsigns);
	print "Total number of states loaded: ". keys(%callstates);
}

sub callSigns
{
	my $sign = doInput("Please enter a callsign");
	my $sent = 0;

	foreach (keys %callsigns) {
		if ($_ eq $sign) {
			print "Information for ". $_;
			my @data = $callsigns{$_};
			print $data[0][1];
			print "";
			print $_ ." is located in ". $data[0][0];
			my @count = split(/;/,$callstates{$data[0][0]});
			print "There are ". (scalar(@count)-1) ." call signs in " .$data[0][0];
			$sent = 1;
		}
	}

	if ($sent == 0) {
		print "Error, callsign: ". $sign ." not found";
	}
}

sub stateSearch
{
	my $state = doInput("Please enter a state");
	my $sent = 0;

	foreach (keys %callstates) {
		if ($_ eq $state) {
			my @signs = split(/;/,$callstates{$_});
			print "Total number of call signs in ". $_ .": ". (scalar(@signs)-1)."\n\n";
			print $callstates{$_};
			$sent = 1;
		}
	}
	if ($sent == 0) {
		print "Error, state: ". $state ." not found";
	}
}
