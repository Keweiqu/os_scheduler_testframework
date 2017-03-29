import subprocess

Class Testcase:
    desc = None
    """a string describes the test"""
    testfile = None
    """test file name"""
    expected = None
    """expected output of the test"""
    timeout = 10
    """number in seconds before the program is killed"""
    
    def __init__(self, testfile, expected, desc=None, timeout=None):
        if desc is None:
            desc = testfile
        self.testfile = testfile
        self.expected = expected
        if timeout is not None:
            self.timeout = timeout
            
    def run(self):
        exec = "test"
        subprocess.run(["gcc"])
        
