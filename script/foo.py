import os, subprocess, glob, argparse
from testcase import Testcase

parser = argparse.ArgumentParser(description='Specify userthread library directory, and test cases directory')
parser.add_argument('-t','--tests', required=True,
                    help='absolute path to test cases dir')
parser.add_argument('-p', '--path', required=True,
                    help='absolute path to shared library dir')

args = parser.parse_args()

class Test:
    dir = "."
    exec = "test"
    def setup(self, dir):
        self.dir = dir
        os.environ['LD_LIBRARY_PATH'] = dir
    def run(self, testcase):
        p1 = subprocess.Popen([
            "gcc",
            "-o",
            self.exec,
            testcase.file,
            "-L"+self.dir,
            "-luserthread"
        ], env=os.environ, stdout=subprocess.PIPE)
        if p1.wait() != 0:
            print("Compilation failed")
            return False
        
        p2 = subprocess.Popen(["./"+self.exec], env=os.environ, stdout=subprocess.PIPE)
        p2.wait()
        stdout,_ = p2.communicate()
        if stdout == testcase.expected:
            print("Passed")
            return True
        else:
            print("Failed - Not equal")
            print(testcase.expected)
            print(stdout)
            return False
    def teardown(self):
        # rm executable
        subprocess.run(["rm", self.exec])
        # rm logger file
        # finger crossed non of other essential files
        # are named Log, log, Logger, logger. etc
        loggers = glob.glob('*log*') + glob.glob("*Log*")
        subprocess.run(["rm"] + loggers)
if __name__ == "__main__":
    t = Test()
    t.setup(args.path)
    cases = glob.glob(args.tests+"*.c")
    for c in cases:
        case = Testcase(c)
        print("Running test case " + case.file)
        t.run(case)
        t.teardown()
        print("\n")
