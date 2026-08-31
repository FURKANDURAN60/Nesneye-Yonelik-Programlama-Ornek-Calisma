public class Thermostat extends Appliance {
    private double temperature;

    public Thermostat(String name, double initialTemperature) {
        super(name);
        this.temperature = initialTemperature;
    }

    public void setTemperature(double temperature) {
        this.temperature = temperature;
        System.out.println(getName() + " sıcaklığı ayarlandı: " + this.temperature + "°C");
    }

    public void increaseTemperature(double amount) {
        temperature += amount;
        System.out.println(getName() + " sıcaklık arttı: " + temperature + "°C");
    }

    public void decreaseTemperature(double amount) {
        temperature -= amount;
        System.out.println(getName() + " sıcaklık azaldı: " + temperature + "°C");
    }

    public double getTemperature() {
        return temperature;
    }
}
