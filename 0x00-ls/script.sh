#!/bin/bash
x=1
while [ $x -le 100 ]
do
  git add scripts_shell.c;
  git commit -m "Fixing script";
  git push;
  git rm scripts_shell.c;
  git add --all .;
  git commit -m "Fixing script";
  git push;
  touch scripts_shell.c;
  x=$(( $x + 1 ))
done