public class Appliance implements Controllable {
    private String name;
    private boolean isOn;

    public Appliance(String name) {
        this.name = name;
        this.isOn = false;
    }

    public String getName() {
        return name;
    }

    @Override
    public void turnOn() {
        if (!isOn) {
            isOn = true;
            System.out.println(name + " açıldı.");
        } else {
            System.out.println(name + " zaten açık.");
        }
    }

    @Override
    public void turnOff() {
        if (isOn) {
            isOn = false;
            System.out.println(name + " kapatıldı.");
        } else {
            System.out.println(name + " zaten kapalı.");
        }
    }

    @Override
    public boolean isOn() {
        return isOn;
    }

    public void status() {
        System.out.println(name + " durumu: " + (isOn ? "AÇIK" : "KAPALI"));
    }
}
