// 飞 机 杯 控制程序
// by 港南二中2323班罗培玮

#include "stm32f103x8.h"

// 引脚定义
// GPIO_PIN_0 控制蠕动
// GPIO_PIN_1 连接干湿传感器
// GPIO_PIN_2 连接复位按钮

#define PULSE_PIN      GPIO_PIN_0
#define PULSE_PORT     GPIOA

#define SENSOR_PIN     GPIO_PIN_1
#define SENSOR_PORT    GPIOA

#define TRIGGER_PIN    GPIO_PIN_2
#define TRIGGER_PORT   GPIOA

// 函数声明
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    uint8_t stop_flag = 0;        // 停止标志位
    uint8_t trigger_state = 0;    // 上次触发状态
    uint8_t current_trigger = 0;  // 当前触发状态

    while (1)
    {
        // 检测是否接收到外部脉冲（上升沿）
        current_trigger = HAL_GPIO_ReadPin(TRIGGER_PORT, TRIGGER_PIN);

        if (current_trigger == GPIO_PIN_SET && trigger_state == GPIO_PIN_RESET)
        {
            // 检测到上升沿，重置停止标志，继续循环
            stop_flag = 0;
            HAL_Delay(10);  // 防抖延时
        }
        trigger_state = current_trigger;

        // 如果已停止，则跳过脉冲输出
        if (stop_flag)
        {
            continue;
        }

        // 输出一个高电平脉冲（持续时间可调，如 100ms），模拟手按摩jb
        HAL_GPIO_WritePin(PULSE_PORT, PULSE_PIN, GPIO_PIN_SET);
        HAL_Delay(100);  // 脉冲宽度
        HAL_GPIO_WritePin(PULSE_PORT, PULSE_PIN, GPIO_PIN_RESET);

        // 延时1秒后再次输出
        HAL_Delay(900);  // 总计1秒

        // 检查干湿传感器是否检测到液体（检测到j液后停止，低电平有效）
        if (HAL_GPIO_ReadPin(SENSOR_PORT, SENSOR_PIN) == GPIO_PIN_RESET)
        {
            stop_flag = 1;  // 设置停止标志
        }
    }
}

// 引脚初始化函数
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // 设置输出脉冲引脚为推挽输出
    GPIO_InitStruct.Pin = PULSE_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(PULSE_PORT, &GPIO_InitStruct);

    // 设置干湿传感器引脚为上拉输入
    GPIO_InitStruct.Pin = SENSOR_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(SENSOR_PORT, &GPIO_InitStruct);

    // 设置外部触发引脚为上拉输入
    GPIO_InitStruct.Pin = TRIGGER_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(TRIGGER_PORT, &GPIO_InitStruct);
}
