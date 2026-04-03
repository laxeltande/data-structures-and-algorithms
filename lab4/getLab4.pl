
#!/usr/local/bin/perl -w
@LL =  ("A", "B", "C", "D", "E", "F", "G", "H");
$name = "";
$userid = $ARGV[0];
@pwend = getpwnam $userid;
$name = $pwend[5];
$start = ord($userid)%8;
$start = $LL[$start];

#$os = `uname`;
#if ($os eq "SunOS\n") {
  $fsm = `/home/courses/coe428/bin/permute $userid`;
#} else {
#  $fsm = `/usr/bin/rsh job "/home/courses/coe428/bin/permute $userid"`;
#}

$msg = "Hello ".$name ."

Your personalized state machine description for Lab 4 (coe 428) follows:\n\n$fsm\n"."Your starting state is: $start \n
   Good luck!\n";
print $msg;

