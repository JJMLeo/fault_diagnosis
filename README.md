# 用偏差来做输入输出

## 1、生成基准数据Database_ref

| 变量 | 维度 | 备注 |
| ----- | ---- | ---- |
| ref_measure | 8×1000×10 |  |
| ref_performance | 8×1000×10 |  |

- Error = 0

- 基准数据没有噪声

- 10个状态点(3500:500:8000)  每个状态点1000个样本

- 还是8个测量参数，8个性能参数

## 2、生成真值数据Database_truth

| 变量 | 维度 | 备注 |
| ----- | ---- | ---- |
| truth_measure | 8×1000×10 |  |
| truth_performance | 8×1000×10 |  |

## 3、计算偏差数据Database_delta

| 变量 | 维度 | 备注 |
| ----- | ---- | ---- |
| delta_measure | 8×1000×10 |  |
| delta_performance | 8×1000×10 |  |

- 输入
$ \Delta f_{j} =\frac{( f_{j} - f_{j}^{ref} )}{f_{j}^{ref}} * 100 $

- 输出
$ \Delta Y_{j} =\frac{( Y_{j} - Y_{j}^{ref} )}{Y_{j}^{ref}} * 100 $

## 4、计算源域数据Database_source

| 变量 | 维度 | 备注 |
| ----- | ---- | ---- |
| delta_measure | 8×1000×3000×10 |  |
| delta_performance | 8×1000×3000×10 |  |

- 循环数为1~3000