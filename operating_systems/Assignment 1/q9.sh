#!/usr/bin/env bash

read -erp 'Enter numeric grade (q to quit): '
case $REPLY in [qQ]) exit;; esac

declare -A cutoffs
cutoffs[F]=59 cutoffs[D]=69 cutoffs[C]=79 cutoffs[B]=89 cutoffs[A]=100

for letter in F D C B A; do
    ((REPLY <= cutoffs[$letter])) && { echo $letter; exit; }
done
echo "Grade out of range."