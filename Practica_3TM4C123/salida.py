import serial as s
Ser=s.Serial('COM5',57600)
Ser.write(b'<')
Ser.write(b'a')
Ser.write(b'n')
Ser.write(b'd')
Ser.write(b'r')
Ser.write(b'e')
Ser.write(b'a')
Ser.write(b'>')


c=Ser.read(10)
print(c)
