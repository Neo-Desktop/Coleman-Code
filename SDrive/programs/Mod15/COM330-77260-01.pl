#!/usr/bin/env perl
################################################
#           Name: Amrit Panesar
# Student Number: 77260
#        Program: 01
################################################

#initialization
use Win32::Console::ANSI;
use Term::ANSIColor;
use Term::ReadKey;
use Data::Dumper qw(Dumper);
use strict;
use warnings;

$\ = "\n";
$| = 1;

#variables
my ($input, $choice, $temp, $hold);
my $debug = 0;
############################lets begin##########
system("cls");
system("color 1e");
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
		doMenuLine("E - Extract and Process string         ");
		doMenuLine("P - Perform a mathematical operation   ");
		doMenuLine("R - Read a directory of files          ");
		doMenuLine("F - Find a pattern in a list of files  ");
		doMenuLine("L - Determine if a word is a palidrome ");
		doMenuLine("-"x(19));
		doMenuLine("Q - Quit                               ");
		print "|"." "x(77)."|";
		print " \\"."_"x(75)."/";
		print $\.$\.$\;
	
		printf "Please enter a menu option: ";
		chomp($input = lc(<>));
		print "\n";
		
		if (defined($input)) {
			if ($input eq 'e') {
				$input = "";
				&doExtract();
			} elsif ($input eq 'p') {
				$input = "";
				&doMath();
			} elsif ($input eq 'r') {
				$input = "";
				&doRead();
			} elsif ($input eq 'f') {
				$input = "";
				&doPattern();
			} elsif ($input eq 'l') {
				$input = "";
				&doPalindrome();
			} elsif ($input eq 'q') {
				last;
			} else {
				$input = undef;
				print "Error, please enter a valid menu option: e, p, r, f, l, or q";
				_anyKey();
			}
		}
	}
}
sub doExtract {
	my $input = doInput("Please enter a string");
	my @chars = split(//, $input);
	print "The string: " .$input . " has " .($#chars + 1). " characters.";
	_anyKey();
}

sub doMath {
	my $input = doInput("Please enter a matematical expression");
	if ($input =~ /[0-9]/) {
		my $output = eval($input);
		if (!$@) {
			print "Result: " .$output;
		} else {
			print "Invalid Expression";
		}		
	} else {
		print "Please include at least one number in your expression";
	}
	_anyKey();
}

sub doRead {
	my $input = doInput("Please enter a valid directory");
	if (opendir(my $dh, $input)) {
		print "Here are all the files in: ". $input;
		while (readdir $dh) {
			print;
		}
	} else {
		print "Unable to open directory: ".$input;
	}
	_anyKey();
}

sub doPattern {
	my $input = doInput("Please enter a valid directory");
	my $grep = doInput("Please enter a filtering expression");
	if (opendir(my $dh, $input)) {
		print "Here are all the files in: ". $input ." that match \"" .$grep. "\"";
		my @filtered;
		$grep = lc($grep);
		foreach my $element (readdir($dh)) {
			$element = lc($element);
			my $index = index($element, $grep);
			if ($debug) {
				print($element . ", " . $grep . ", " . ($index > -1));
			}
			if ($index > -1) {
				push(@filtered, $element);
			}
		}
		if ($debug) {
			print "\n";
			unshift(@filtered, "Elements in the filtered list: ");
			print "Total elements: " . scalar(@filtered);
		}
		if (scalar(@filtered) > 0) {
			foreach (@filtered) {
				print;
			}
		} else {
			print "No matches found";
		}
	} else {
		print "Unable to open directory: ".$input;
	}
	_anyKey();
}

sub doPalindrome {
	my $input = doInput("Please enter a palindrome");
	my @chars = split(//, $input);
	my @rev = ();
	for (my $j = 0, my $i = $#chars; $i > -1; $i--, $j++) {
		$rev[$j] = $chars[$i];
	}
	my $output = join('', @rev);
	if ($debug) {
		print "Input: ". $input;
		print "Output: ". $output;
	}
	if ($input eq $output) {
		print "the word or phrase: ". $input ." IS a palindrome.";
	} else {
		print "the word or phrase: ". $input ." is NOT a palindrome.";
	}
	_anyKey();
}
