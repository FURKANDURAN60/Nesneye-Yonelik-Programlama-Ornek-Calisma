public class SecuritySystem extends Appliance {
    private boolean armed;

    public SecuritySystem(String name) {
        super(name);
        this.armed = false;
    }

    public void arm() {
        if (!isOn()) {
            turnOn();
        }
        armed = true;
        System.out.println(getName() + " güvenlik sistemi devrede.");
    }

    public void disarm() {
        armed = false;
        System.out.println(getName() + " güvenlik sistemi devre dışı.");
    }

    public boolean isArmed() {
        return armed;
    }

    @Override
    public void turnOff() {
        super.turnOff();
        armed = false;
    }
}
