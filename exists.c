import os
import sys
import shlex
import signal

def execute_command(command) :
args = shlex.split(command)
try :
os.execvp(args[0], args)
except FileNotFoundError :
print(f"Command not found: {args[0]}")
def main() :
while True :
try :
command = input(":) ")
except KeyboardInterrupt :
print("\nExiting shell.")
sys.exit(0)
if command.strip() == "" :
continue
if '/' in command :
execute_command(command)
else
:
paths = os.environ.get("PATH").split(":")
found = False
for path in paths :
full_path = os.path.join(path, command)
if os.path.exists(full_path) :
execute_command(full_path)
found = True
break
if not found :
print(f"Command not found: {command}")
if __name__ == "__main__" :
main()
