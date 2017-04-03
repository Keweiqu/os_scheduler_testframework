import subprocess, os
from testcase import Testcase

class Test:
    dir = "."
    exec = "test"
    timeout = 10
    def __init__(self, exec=None, timeout=None):
        if exec is not None:
            self.exec = exec
        if timeout is not None:
            self.timeout = timeout
        
    def setup(self, dir):
        """set up the correct environment for testing
        Args:
        dir: a relative path from the calling directory 
        to the student's project folder
        """
        self.dir = os.getcwd() + "/"+ dir


    def run(self, testcase):
        p1 = subprocess.Popen(["gcc", "-o", "test", "../tests/0.c", "-L/home/kqu/cs355/proj4/kchang", "-luserthread"], env=os.environ, stdout=subprocess.PIPE)
        p1.wait()
        p2 = subprocess.Popen(["./test"], env=os.environ, stdout=subprocess.PIPE)
        p2.wait()
        stdout, _ = p2.communicate()
        return stdout

    def teardown(self):
        subprocess.run(["rm", self.exec])


if __name__ == "__main__":
    os.environ['LD_LIBRARY_PATH'] = "home/kqu/cs355/proj4/kchang"
    case = Testcase("../tests/0.c", b'I am func\nMain exiting\n')
    test = Test()
    test.run(case)
    #test.teardown()
    
