#!/bin/bash

clear

echo "ABCDEFGHIJKLMNOPQRSTUVWQYZ" | tr '[a-zA-Z]' '[e-za-dE-ZA-D]'
echo "EFGHIJKLMNOPQRSTUVWXYZABCD" | tr '[e-za-dE-ZA-D]' '[a-zA-Z]'

echo "this is a test on 1357" | tr '0-9' 'a-eA-E'
echo "this is a test on 1357" | tr '4-9' 'a-z-A-z' 
echo "this is a test on 1357" | tr '0-9' '0' 

