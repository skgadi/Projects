import serial
import time
import tkinter as tk

# Configura el puerto según tu sistema
arduino = serial.Serial('COM12', 9600, timeout=1)
time.sleep(2)  # Espera a que el Arduino reinicie

def enviar_comando(motor_id, angulo):
    comando = f"S{motor_id}{angulo}\n"
    arduino.write(comando.encode('utf-8'))
    print(f"Comando enviado: {comando.strip()}")

# Interfaz gráfica
ventana = tk.Tk()
ventana.title("Control de Servos")

sliders = []

for i in range(1, 8):
    tk.Label(ventana, text=f"Motor {i}").pack()
    slider = tk.Scale(ventana, from_=0, to=180, orient=tk.HORIZONTAL,
                      command=lambda val, m=i: enviar_comando(m, val))
    slider.pack()
    sliders.append(slider)

ventana.mainloop()