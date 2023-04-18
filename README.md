# LastTrench
![alt text](https://i.imgur.com/0GbSwUl.png)


LastTrench (new version my findperson) - Finding what the person left behind online.
You give the software a name and it searches social media pages and websites with that name.

You can also save them to a txt file.
Both are possible.

- LastTrench is fully cross-platform, on Windows compile through MinGW, I tried but could not connect the libraries :)
- Your link bases must also lie in bases, otherwise it will not find them.
- The interface is similar to nmap, yes, I just think it is the most optimized interface.
- I didn't add unnecessary arguments just to take up space in the help menu, why?

## Using
```
LastTrench: Finding what the person left behind online.

usage: ./lasth [TARGETS (1,2,3) ] [ARGUMENTS]


arguments main:
  -h, --help            Show this help message and exit.
  -v, --version         Display version information and dependencies.
  --db, --debug         Saving and outputting even pages that are not working.
  -T, --timeout<MS>     Set a delay when receiving a page.
  --thanks              Display all contributors.

arguments save:
  --txt <FILE>          Save output to txt.
  --html <FOLDER/>      Save output to html.

arguments user:
  -p, --proxy <PROXY>   Using proxy server.
  --base <PATH>         Specify your file with links.
  --code <CODE>         Specify your correct answer code.
```
## Proxy using
```
--proxy http://ip:port
      HTTP Proxy.

--proxy https://ip:port
      HTTPS Proxy.

--proxy socks4://ip:port
      SOCKS4 Proxy.

--proxy socks4a://ip:port
      SOCKS4a Proxy.

--proxy socks5://ip:port
      SOCKS5 Proxy.

--proxy socks5h://ip:port
      SOCKS5 Proxy.
```

## Example
```
./lastn lomaster,lol --txt result.txt

    Searches for pages called lomaster and lol.
    And then saves (TXT).
    
./lastn lomaster --txt result.txt --db

    Searches for pages called lomaster.
    And then saves (even non-working ones) in txt.
```

## Compile
-  ARCH & MANJARO  
        **sudo pacman -S curl**
       
- DEBIAN      
        **sudo apt-get install libcurl4-openssl-dev**

- git clone https://github.com/Lomasterrrr/lasth.git
- cd lasth
- make

#### Dependencies:
- gcc
- libcurl
