public class Light extends Appliance {
    private int brightness;

    public Light(String name) {
        super(name); //kalıtım yoluyla Appliance sınıfının yapıcı metodunu çağırıyoruz
        this.brightness = 50;
    }

    public void setBrightness(int brightness) {
        if (brightness < 0) {
            brightness = 0;
        } else if (brightness > 100) {
            brightness = 100;
        }

        this.brightness = brightness;
        System.out.println(getName() + " parlaklık seviyesi: " + this.brightness + "%");
    }

    public int getBrightness() {
        return brightness;
    }

    @Override
    public void turnOn() {
        super.turnOn();
        if (isOn() && brightness == 0) {
            setBrightness(50);
        }
    }
}
