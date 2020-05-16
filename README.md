# Cryphographic-System-With-Custom-Feistel-Networks
    by vdsau 05.06.2016
    
# Platform
  Cryphographic system with custom Feistel networks for Windows
    Written in Builder C++ 6.
    
# Description 
  Program allows to cipher or decipher personal files.
  
  When user select file, system get file metadata, such as
  size, name, path, extesion.
  
  After choosing file, user can generate password with 
  specified length and characters set.
  
  When all setting are setuped, press "OK", then
  system analyze file extension:
    1.) Crypted files have extension .LOL,
    this files automatically decrypting and saving to
    "\files\Res\Розшифровані файли".
    2.) All others files, automatically crypting by system
    and save to "\files\Res\Зашифровані файли".
    
# Attention 
  1.) Crypting or decripting time depend of file size,
  Big file -> Slower, Small file -> Faster.
  2.) Crypted file always bigger then decrypted,
  because updating metadata of file.
