set PROGRAM="%~1"

echo BAD INPUT
%PROGRAM% 
%PROGRAM% 1
%PROGRAM% abc
%PROGRAM% 1 1
%PROGRAM% 1_2_1           
%PROGRAM% 1-2-1
%PROGRAM% 1~2~1
%PROGRAM% 1a 1 1
%PROGRAM% IAmInteger 1 1
%PROGRAM% 999999999999999999 1 1
%PROGRAM% 1.12345 1 1
%PROGRAM% -1 1 1
%PROGRAM% -0 1 1
%PROGRAM% -1.2 1 1
%PROGRAM% 1,1 2 1
%PROGRAM% 1 1/2 1
%PROGRAM% 1 1@2 1
%PROGRAM% 1 1~2 1
%PROGRAM% /1/ 2 1
%PROGRAM% '1.1' 2 1

echo VALID INPUT
%PROGRAM% 1.123 1 1
%PROGRAM% 2 5 4
%PROGRAM% 4.33 2.13 5.15
%PROGRAM% 2.2 2.2 1.2
%PROGRAM% 7 7 5
%PROGRAM% 7 7 7
%PROGRAM% 5.15 5.15 5.15
%PROGRAM% "1.1" 2 1

exit 0