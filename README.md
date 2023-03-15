# LastTrench
![alt text](https://i.imgur.com/N8SaIwS.png)


LastTrench (new version my findperson) - Finding what the person left behind online.
You give the software a name and it searches social media pages and websites with that name.

Has the ability to download working pages to an html file.
You can also save them to a txt file.
Both are possible.

#### Dependencies:
- gcc
- libcurl
- PC

## Using
```
LastTrench: Finding what the person left behind online.


usage: ./Lastn  [-h] [--version] [-n NICKNAME] [--txt]
                [-d] [-t TIMEOUT] [-p PROTC://IP:PORT]
                [--html] [--ru]

optional arguments:
  -n, --name            Set target name.
  -h, --help            Show this help message and exit.
  --version, -v         Display version information and dependencies.
  -d, --db, -debug      Saving and outputting even pages that are not working.
  -t, --timeout         Set a delay when receiving a page.
  -x, --oX              Save the output to a text file.
  -l, --oL              Save output to html.
  -p, --proxy           Using proxy server.
  --ru                  Это меню на нормальной языке).
```

## Compile
- gitclone https://github.com/Lomasterrrr/LastTrench.git
- cd LastTrench
- make

## Download build
- 0.3.0 - https://github.com/Lomasterrrr/LastTrench/releases/tag/Last-Trench
