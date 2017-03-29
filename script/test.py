import subprocess, os

class Test:
    dir = "."
    def setup(self, dir):
        """set up the correct environment for testing
        Args:
        dir: a relative path from the calling directory 
        to the student's project folder
        """
        self.dir = os.getcwd() + "/"+ dir
        subprocess.run([])





if __name__ == "__main__":
    Test
    
