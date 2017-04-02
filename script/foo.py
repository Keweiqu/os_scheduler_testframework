import os, subprocess

class Test:
    dir = "."
    exec = "test"
    def setup(self, dir):
        self.dir = dir
        os.environ['LD_LIBRARY_PATH'] = dir
    def run(self):
        p1 = subprocess.Popen(["gcc", "-o", self.exec, "../tests/0.c", "-L"+self.dir, "-luserthread"], env=os.environ, stdout=subprocess.PIPE)
        p1.wait()
        p2 = subprocess.Popen(["./"+self.exec], env=os.environ, stdout=subprocess.PIPE)
        p2.wait()
        stdout,_ = p2.communicate()
        print(stdout)
if __name__ == "__main__":
    t = Test()
    t.setup("/home/kqu/cs355/proj4/kchang")
    t.run()
