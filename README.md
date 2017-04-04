# os_scheduler_testframework

## program layout
./
test.py - Runs test suites
testcase.py - Defines the Testcase object

## How to run
python test.py -t /absolute/path/to/test/files -d /absolute/path/to/sharedlib/dir

## Design
For each .c test file, it should contain an expected output as *one line* immediately following `Expected:: `
The python script will grep this line and parse out the expected output and compare with the sharedlibrary's output

## TODO
(1) Add build section. Currently we need to manually compile the shared lib because some people dont have a makefile.
In the future, we need to require all students to provide a Makefile to build the shared lib so that we can automate the build process as well.
(2) Come up with test cases for priority scheduling. Currently, this functionality is tested by eye ball people's logger
and running a test with expected CPU utilization rate. Then `top` to see what is the real CPU utilization rate.
However this method effectively requires the only process running on the machine is our test.
