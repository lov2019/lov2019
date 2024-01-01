from rich import console
import os
rc=True
con=console.Console()
def r():
    if rc:
        rc=False
    else:
        rc=True
    return
def x():
    exit(0)
    return
def c():
    try:
        os.chdir(input("chdir>"))
    except:
        con.print("Can not change work dir!",style="bold red")
    else:
        con.print("Change work dir finish!",style="bold green")
    return
        
