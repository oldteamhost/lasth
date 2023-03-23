# LastTrench
![alt text](https://i.imgur.com/moVml9K.png)


LastTrench (new version my findperson) - Finding what the person left behind online.
You give the software a name and it searches social media pages and websites with that name.

Has the ability to download working pages to an html file.
You can also save them to a txt file.
Both are possible.

## Download build
- 0.3.8 (linux) - https://github.com/Lomasterrrr/LastTrench/releases/tag/Last-Trench-0.3.8

## Using
```
LastTrench: Finding what the person left behind online.


usage: ./Lastn [-h] [--version] [-n NICKNAME] [--txt]
               [-d] [-t TIMEOUT] [-p PROTC://IP:PORT]
               [--html] [--ru] [--color] [--code CODE]


argumentation description:
  -n, --name            Set target name.
  -h, --help            Show this help message and exit.
  --version, -v         Display version information and dependencies.
  -t, --timeout         Set a delay when receiving a page.
  -p, --proxy           Using proxy server.
  --debug               Saving and outputting even pages that are not working.
  --html                Save the output to a text file.
  --txt                 Save output to html.
  --path                Specify your file with links.
  --color               Disable color.
  --code                Specify your correct answer code.
  --ru                  Это меню на нормальной языке).
```

## Example
```
./lastn -n lomaster --txt

    Searches for pages called lomaster.
    And then saves (TXT).
    
./lastn -n lomaster --txt --debug --html

    Searches for pages called lomaster.
    And then saves (even non-working ones) in html and txt.
```
## Sites base

## Compile
- git clone https://github.com/Lomasterrrr/LastTrench.git
- cd LastTrench/0.3.8
- make

#### Dependencies:
- gcc
- libcurl
- PC
