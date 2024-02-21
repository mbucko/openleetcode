# logger.py

_verbose = False

def red(text):
    return f"\033[91m{text}\033[0m"

def green(text):  
    return f"\033[92m{text}\033[0m"

def set_verbose(verbose: bool):
    global _verbose
    _verbose = verbose

def log(message: str):
    if _verbose:
        print(message)
