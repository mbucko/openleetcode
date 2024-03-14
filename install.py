import argparse
import fnmatch
import os
import shutil
import subprocess

from distutils import dir_util

if os.name == "nt":
    default_prefix = "C:\\Program Files"
    script_sufix = ".bat"
else:
    default_prefix = "/usr/local"
    script_sufix = ".sh"

def installUI(src_dir, build_dir, install_dir):
    ui_build_dir = os.path.join(build_dir, "ui")
    if os.path.exists(ui_build_dir):
        shutil.rmtree(ui_build_dir)

    src_dir = os.path.join(src_dir, "src", "ui")
    shutil.copytree(src_dir, ui_build_dir)

    cmd_npm_install = "npm install"
    cmd_npx_build = f"npx electron-packager . --out={install_dir} --overwrite"

    print(f"Installing OpenLeetCodeUI dependencies...")
    result = subprocess.run(cmd_npm_install,
                        stdout=subprocess.PIPE,
                        stderr=subprocess.STDOUT,
                        shell=True,
                        cwd=ui_build_dir)
    if result.returncode != 0:
        print(result.stdout.decode('utf-8'))
        raise RuntimeError(f"Error running the command: {cmd_npm_install}")

    print(f"Building OpenLeetCodeUI...")
    result = subprocess.run(cmd_npx_build,
                        stdout=subprocess.PIPE,
                        stderr=subprocess.STDOUT,
                        shell=True,
                        cwd=ui_build_dir)
    if result.returncode != 0:
        print(result.stdout.decode('utf-8'))
        raise RuntimeError(f"Error running the command: {cmd_npx_build}")
    
    openleetcode_ui_dir = os.path.join(
        install_dir,
        [
            d for d in os.listdir(install_dir)
            if fnmatch.fnmatch(d, "OpenLeetCodeUI-*-*")
        ][0]
    )

    new_openleetcode_ui_dir = os.path.join(install_dir, "OpenLeetCodeUI")
    if os.path.exists(new_openleetcode_ui_dir):
        shutil.rmtree(new_openleetcode_ui_dir)

    os.rename(openleetcode_ui_dir, new_openleetcode_ui_dir)

    if os.name == "nt":
        script = "openleetcodeui.bat"
    elif os.name == "posix":
        script = "openleetcodeui.sh"
    else:
        raise RuntimeError("Unsupported OS")
    
    print(f"Installing OpenLeetCodeUI...")
    script = os.path.join(src_dir, script)
    if not os.path.exists(script):
        raise FileNotFoundError(f"No file found at {script}")
    shutil.copy(script, install_dir)
    
    print("OpenLeetCodeUI installed at", new_openleetcode_ui_dir)

def installOpenLeetCode(src_dir, install_dir):
    print(f"Installing OpenLeetCode...")
    data_dir = os.path.join(src_dir, 'data')
    if not os.path.exists(data_dir):
        raise FileNotFoundError(f"No data directory found at {data_dir}")

    dir_util.copy_tree(data_dir, install_dir)

    schema_file = os.path.join(src_dir, "src", "schema", "results_validation_schema.json")
    if not os.path.exists(schema_file):
        raise FileNotFoundError(f"No schema file found at {schema_file}")
    shutil.copy(schema_file, install_dir)

    if os.name == "nt":
        script = "openleetcode.bat"
    elif os.name == "posix":
        script = "openleetcode.sh"
    else:
        raise RuntimeError("Unsupported OS")

    app_files = [
        "functionextractor.py",
        "logger.py",
        "openleetcode.py",
        "resultsvalidator.py",
        "testrunner.py",
        script
    ]

    for file in app_files:
        file = os.path.join(src_dir, "src", "app", file)
        if not os.path.exists(file):
            raise FileNotFoundError(f"No file found at {file}")
        shutil.copy(file, install_dir)
    
    print("OpenLeetCode installed at", install_dir)

def main():
    print("OpenLeetCode Installer")

    parser = argparse.ArgumentParser(description="Installer for OpenLeetCode")
    parser.add_argument("--build_dir", help="Build directory", default="build")
    parser.add_argument("--prefix", help="Installation prefix", default=default_prefix)
    parser.add_argument("--enable_ui", help="Enable UI installation", action="store_true", default=False)

    args = parser.parse_args()

    src_dir = os.path.dirname(os.path.abspath(__file__))
    build_dir = os.path.abspath(args.build_dir)
    if not os.path.exists(build_dir):
        os.makedirs(build_dir)

    install_dir = os.path.abspath(os.path.join(args.prefix, "OpenLeetCode"))
    if not os.path.exists(install_dir):
        os.makedirs(install_dir)

    installOpenLeetCode(src_dir, install_dir)

    if args.enable_ui:
        installUI(src_dir, build_dir, install_dir)

    print(
        f"Installation complete!\nYou can now run OpenLeetCode using "
        f"openleetcode{script_sufix}"
        f"{ ' or openleetcodeui' + script_sufix if args.enable_ui else ''}."
    )

if __name__ == '__main__':
    main()