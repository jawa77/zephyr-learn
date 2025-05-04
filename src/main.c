#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>


// just fetch node label from device tree overlay
#define GLED_NODE DT_NODELABEL(gled)

// from tha identifier we create gpio spec (struct contains info such as port, pin, flags)
// these gled spec fetch from device tree overlay rpi_pico.overlay
static const struct gpio_dt_spec gled_spec = GPIO_DT_SPEC_GET(GLED_NODE, gpios);

int main(void)
{
    // check if the device is ready

    int rc=0;

    rc=gpio_is_ready_dt(&gled_spec);

    if (!rc) {
        // "GPIO device is not ready
        printk("GPIO device is not ready[%d]\n", rc);
        return rc;
    }

    rc=gpio_pin_configure_dt(&gled_spec, GPIO_OUTPUT_ACTIVE);
    if (rc<0) {
        // "GPIO pin configuration failed
        printk("Gled pin configuration failed[%d]\n", rc);
        return rc;
    }


    // 1U means 1 unsigned int
   while (1)
   {
   rc= gpio_pin_set_dt(&gled_spec, 1U);
   if(rc < 0){
    printk("gled can't set high");
    return rc;
   }
    k_msleep(1000);
    rc=gpio_pin_set_dt(&gled_spec, 0U);
    if(rc < 0){
        printk("gled can't set low");
        return rc;
    }
    k_msleep(1000);
   }
   
}