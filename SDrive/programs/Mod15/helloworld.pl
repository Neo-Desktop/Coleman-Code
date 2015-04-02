#!/bin/env perl
$\ = "\n";

print "Please enter a thing." . $\;
chomp($input = <STDIN>);
print $input;
