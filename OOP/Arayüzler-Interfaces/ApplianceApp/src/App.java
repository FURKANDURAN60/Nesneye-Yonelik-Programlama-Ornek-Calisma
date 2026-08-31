public class App {
    public static void main(String[] args) {
        Controllable[] devices = {
            new Light("Oda Lambası"),
            new Thermostat("Merkezi Isıtma", 21.0),
            new SecuritySystem("Ev Güvenlik Sistemi")
        };

        System.out.println("=== Akıllı Ev Yönetim Sistemi ===");

        for (Controllable device : devices) {
            if (device instanceof Light) {
                Light light = (Light) device;
                light.turnOn();
                light.setBrightness(75);
                light.status();
            } else if (device instanceof Thermostat) {
                Thermostat thermostat = (Thermostat) device;
                thermostat.turnOn();
                thermostat.setTemperature(24.5);
                thermostat.status();
            } else if (device instanceof SecuritySystem) {
                SecuritySystem securitySystem = (SecuritySystem) device;
                securitySystem.arm();
                securitySystem.status();
            }

            System.out.println();
        }

        System.out.println("Tüm cihazlar yönetildi.");
    }
}
