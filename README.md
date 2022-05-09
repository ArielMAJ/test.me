As it is, the github actions/workflow requires your code to print EXACTLY as what's in the '.out' file. 

This includes "trailing spaces" at the end of each line (meaning your code shouldn't have them) and new lines at the end of the file. 

Any variation at all (e.g. you forget to print "\n" and the x.out file expects it) will result in failing tests.

Once one test fails, sometimes the "workflow" won't finish testing it all.
