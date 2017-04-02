import os, subprocess

class Test:
    dir = "."
    def setup(self, dir):
        self.dir = dir
        os.environ['LD_LIBRARY_PATH'] = dir
    def run(self):
        p1 = subprocess.Popen(["gcc", "-o", "test", "../tests/0.c", "-L/home/kqu/cs355/proj4/kchang", "-luserthread"], env=os.environ, stdout=subprocess.PIPE)
        p1.wait()
        p2 = subprocess.Popen(["./test"], env=os.environ, stdout=subprocess.PIPE)
        p2.wait()
        stdout,_ = p2.communicate()
        print(stdout)
if __name__ == "__main__":
    t = Test()
    t.setup("/home/kqu/cs355/proj4/kchang")
    t.run()
