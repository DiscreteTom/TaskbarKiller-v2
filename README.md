# TaskbarKiller-v2

No GUI, no icon, simpler than [TaskbarKiller](https://github.com/DiscreteTom/TaskBarKiller).

## Usage

First, turn on **Automatically hide the taskbar** in system settings.

Press `Win` + `~` to hide windows taskbar, press again to bring it back.

To make it startup with system, run `reg-gen.bat` in the same folder of `TaskbarKiller-v2.exe` to get `start.reg`, then run `start.reg`.

## How to stop this?

Press `Ctrl` + `Shift` + `Esc` to open your Task Manager, find `TaskbarKiller-v2` and end that task.

## How to recover my taskbar?

Press `Ctrl` + `Shift` + `Esc` to open your Task Manager, find `Windows Explorer` and restart that task.

## Known issue

While taskbar is hidden, you could NOT use `Win` + `Number` to switch applications. You can use `Alt` + `Tab` to switch applications, or you can use [TaskbarKiller-v3](https://github.com/DiscreteTom/TaskbarKiller-v3).

## Build

MSVC(Visual Studio 2017)
