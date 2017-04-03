import subprocess
class Testcase:
    desc = None
    expected = None
    file = None
    def __init__(self, file, desc=None):
        self.file = file
        if desc is not None:
            self.desc = desc
        p = subprocess.run([
            "grep",
            "Expected:: ",
            file
        ], stdout=subprocess.PIPE)
        self.expected = p.stdout.decode('utf-8').split('::')[1].strip().replace('\\n', '\n').encode('utf-8')
        
