import numpy as np
import matplotlib.pyplot as plt
from scipy.special import fresnel

# Подготовка данных
x = np.linspace(-5, 12, 1500)

# 1 и 2: Базовые функции Френеля
S, C = fresnel(x)

def get_i(x_range, x0):
    # Функция интенсивности (квадрат модуля суммы фазоров)
    s1, c1 = fresnel(x_range)
    s2, c2 = fresnel(x0 - x_range)
    return (c1 + c2)**2 + (s1 + s2)**2

# 3, 4, 5: Интенсивности для разных x0 (разные числа Френеля)
I_large = get_i(x, 10.0) # NF >> 1
I_min   = get_i(x, 2.1)  # NF ~ 1 (провал в центре)


plt.figure(figsize=(12, 8))

# Рисуем всё в одном окне
plt.plot(x, C,       label='1. C(x)', color='blue', alpha=0.6)
plt.plot(x, S,       label='2. S(x)', color='red', alpha=0.6)
plt.plot(x, I_large, label='3. Интенсивность (NF >> 1, x0=10)', color='green', lw=2)
plt.plot(x, I_min,   label='4. Интенсивность (NF ~ 1, x0=2.1, min)', color='orange', lw=2)


# Настройка осей и легенды
plt.title('Все функции Френеля и профили интенсивности в одном окне')
plt.xlabel('x')
plt.ylabel('Значение / Интенсивность')
plt.grid(True, linestyle='--', alpha=0.5)
plt.legend(loc='upper right')
plt.axhline(0, color='black', lw=1)

plt.tight_layout()
plt.show()