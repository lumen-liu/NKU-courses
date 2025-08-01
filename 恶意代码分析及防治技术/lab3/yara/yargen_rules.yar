/*
   YARA Rule Set
   Author: yarGen Rule Generator
   Date: 2023-09-25
   Identifier: 
   Reference: https://github.com/Neo23x0/yarGen
*/

/* Rule Set ----------------------------------------------------------------- */

rule Lab03_01 {
   meta:
      description = " - file Lab03-01.exe"
      author = "yarGen Rule Generator"
      reference = "https://github.com/Neo23x0/yarGen"
      date = "2023-09-25"
      hash1 = "eb84360ca4e33b8bb60df47ab5ce962501ef3420bc7aab90655fd507d2ffcedd"
   strings:
      $s1 = "vmx32to64.exe" fullword ascii
      $s2 = "SOFTWARE\\Classes\\http\\shell\\open\\commandV" fullword ascii
      $s3 = " www.practicalmalwareanalysis.com" fullword ascii
      $s4 = "CONNECT %s:%i HTTP/1.0" fullword ascii
      $s5 = "advpack" fullword ascii
      $s6 = "VideoDriver" fullword ascii
      $s7 = "AppData" fullword ascii /* Goodware String - occured 74 times */
      $s8 = "6I*h<8" fullword ascii /* Goodware String - occured 1 times */
      $s9 = "StubPath" fullword ascii /* Goodware String - occured 1 times */
      $s10 = "WinVMX32-" fullword ascii
      $s11 = "Software\\Microsoft\\Active Setup\\Installed Components\\" fullword ascii /* Goodware String - occured 4 times */
      $s12 = "^-m-m<|<|<|M" fullword ascii
   condition:
      uint16(0) == 0x5a4d and filesize < 20KB and
      8 of them
}

rule Lab03_03 {
   meta:
      description = " - file Lab03-03.exe"
      author = "yarGen Rule Generator"
      reference = "https://github.com/Neo23x0/yarGen"
      date = "2023-09-25"
      hash1 = "ae8a1c7eb64c42ea2a04f97523ebf0844c27029eb040d910048b680f884b9dce"
   strings:
      $s1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                        ' */
      $s2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   ' */
      $s3 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ' */
      $s4 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                                                              ' */
      $s5 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                                                                                               ' */
      $s6 = "aAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                 ' */
      $s7 = "\\svchost.exe" fullword ascii
      $s8 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                          ' */
      $s9 = "BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                                                                                               ' */
      $s10 = "AAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                    ' */
      $s11 = "AAAAAABAAAAA" ascii /* base64 encoded string '     @   ' */
      $s12 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ' */
      $s13 = "AAAqAAApAAAsAAArAAAuAAAtAAAwAAAvAAAyAAAxAAA" fullword ascii /* base64 encoded string '  *  )  ,  +  .  -  0  /  2  1  ' */
      $s14 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ascii /* base64 encoded string '                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        *' */
      $s15 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAq" fullword ascii /* base64 encoded string '                                                        *' */
      $s16 = "wqpwLKla/.5a$/.4&)a21 \"$a'.3a5)3$ %a% 5 LKALK #/.3, -a13.&3 ,a5$3,(/ 5(./LKAAAA" fullword ascii
      $s17 = "- 22AA13 \"5(\" -, -6 3$ / -82(2o-.&AAAAaAAA" fullword ascii
      $s18 = "+A+A+A+A" fullword ascii /* reversed goodware string 'A+A+A+A+' */
      $s19 = "(\"3.2.'5a" fullword ascii /* hex encoded string '2Z' */
      $s20 = "wqswLKla/.5a$/.4&)a21 \"$a'.3a25%(.a(/(5( -(; 5(./LKAAAA" fullword ascii
   condition:
      uint16(0) == 0x5a4d and filesize < 200KB and
      8 of them
}

rule Lab03_04 {
   meta:
      description = " - file Lab03-04.exe"
      author = "yarGen Rule Generator"
      reference = "https://github.com/Neo23x0/yarGen"
      date = "2023-09-25"
      hash1 = "6ac06dfa543dca43327d55a61d0aaed25f3c90cce791e0555e3e306d47107859"
   strings:
      $s1 = "http://www.practicalmalwareanalysis.com" fullword ascii
      $s2 = "%SYSTEMROOT%\\system32\\" fullword ascii
      $s3 = " HTTP/1.0" fullword ascii
      $s4 = " Manager Service" fullword ascii
      $s5 = "UPLOAD" fullword ascii /* Goodware String - occured 1 times */
      $s6 = "DOWNLOAD" fullword ascii /* Goodware String - occured 26 times */
      $s7 = "command.com" fullword ascii /* Goodware String - occured 55 times */
      $s8 = "COMSPEC" fullword ascii /* Goodware String - occured 140 times */
      $s9 = "\"WWSh(" fullword ascii /* Goodware String - occured 1 times */
      $s10 = "SOFTWARE\\Microsoft \\XPS" fullword ascii
      $s11 = "k:%s h:%s p:%s per:%s" fullword ascii
      $s12 = " >> NUL" fullword ascii
      $s13 = "/c del " fullword ascii
      $s14 = "6KRich" fullword ascii
   condition:
      uint16(0) == 0x5a4d and filesize < 200KB and
      8 of them
}

rule Lab03_02 {
   meta:
      description = " - file Lab03-02.dll"
      author = "yarGen Rule Generator"
      reference = "https://github.com/Neo23x0/yarGen"
      date = "2023-09-25"
      hash1 = "5eced7367ed63354b4ed5c556e2363514293f614c2c2eb187273381b2ef5f0f9"
   strings:
      $x1 = "%SystemRoot%\\System32\\svchost.exe -k " fullword ascii
      $x2 = "cmd.exe /c " fullword ascii
      $s3 = "RegOpenKeyEx(%s) KEY_QUERY_VALUE error ." fullword ascii
      $s4 = "Lab03-02.dll" fullword ascii
      $s5 = "practicalmalwareanalysis.com" fullword ascii
      $s6 = "RegOpenKeyEx(%s) KEY_QUERY_VALUE success." fullword ascii
      $s7 = "GetModuleFileName() get dll path" fullword ascii
      $s8 = "dW5zdXBwb3J0" fullword ascii /* base64 encoded string 'unsupport' */
      $s9 = "Y29ubmVjdA==" fullword ascii /* base64 encoded string 'connect' */
      $s10 = "OpenService(%s) error 2" fullword ascii
      $s11 = "OpenService(%s) error 1" fullword ascii
      $s12 = "CreateService(%s) error %d" fullword ascii
      $s13 = "You specify service name not in Svchost//netsvcs, must be one of following:" fullword ascii
      $s14 = "RegQueryValueEx(Svchost\\netsvcs)" fullword ascii
      $s15 = "netsvcs" fullword ascii
      $s16 = "serve.html" fullword ascii
      $s17 = "DependOnService" fullword ascii
      $s18 = ":$:2:K:U:\\:l:" fullword ascii
      $s19 = "uninstall is starting" fullword ascii
      $s20 = "uninstall success" fullword ascii
   condition:
      uint16(0) == 0x5a4d and filesize < 70KB and
      1 of ($x*) and 4 of them
}

rule practicalmalwareanalysis {
   meta:
      description = " - file practicalmalwareanalysis.log"
      author = "yarGen Rule Generator"
      reference = "https://github.com/Neo23x0/yarGen"
      date = "2023-09-25"
      hash1 = "7a51b763f66faecf97c562e58ec2d92f2fff6c19923720d93f72c50a1c8309a3"
   strings:
      $x1 = "C:\\WINDOWS\\system32\\cmd.exe]" fullword ascii
      $s2 = "practicalmalwareanalysis.log - " fullword ascii
      $s3 = "svchost.exe:3408 Properties]" fullword ascii
      $s4 = "Dependency Walker - [Lab03-04.exe]]" fullword ascii
      $s5 = ".txt - " fullword ascii
      $s6 = "Process Monitor Filter]" fullword ascii
      $s7 = "Process Explorer]" fullword ascii
      $s8 = "[Window: " fullword ascii
      $s9 = "Chapter_3L]" fullword ascii
      $s10 = "test[TAB]" fullword ascii
      $s11 = "PEiD v0.95]" fullword ascii
      $s12 = "practical" fullword ascii /* Goodware String - occured 1 times */
      $s13 = "cBACKSPACE" fullword ascii
      $s14 = "Program Manager]" fullword ascii
      $s15 = "a[TAB]" fullword ascii
      $s16 = "[ENTER]" fullword ascii
      $s17 = "s[TAB] [CAPS LOCK]l[CAPS LOCK][TAB][TAB][TAB][TAB]" fullword ascii
   condition:
      uint16(0) == 0x0a0d and filesize < 1KB and
      1 of ($x*) and 4 of them
}

/* Super Rules ------------------------------------------------------------- */

