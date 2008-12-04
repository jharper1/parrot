#!/home/tewk/srcs/parrot/perl6

# $Id$

use v6;

evalfile('./ncigen.pbc', lang => 'Parrot');
evalfile('./compreg.pir', lang => 'Parrot');

my $fn = @*ARGS[0];
my $pp_fn = mktempfile('ptemp');

run("gcc -x c -E $fn > $pp_fn");
my $compiler = compreg('NCIGEN');
my $ast = $compiler.parse(slurp($pp_fn));
say +$ast;
for $ast.item() -> $x {
  say "====================================================";
  say $x;
}



sub mktempfile($prefix) {
  sub nonce() { ".{$*PID}." ~ int 1000.rand }
  $prefix ~ nonce;
}

