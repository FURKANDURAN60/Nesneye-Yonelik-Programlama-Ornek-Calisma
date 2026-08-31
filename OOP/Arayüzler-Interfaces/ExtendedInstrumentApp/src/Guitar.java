public  class Guitar implements Instrument, ElectronicInstrument {
    @Override
    public void play() {
        System.out.println("Guitar is playing");
    }

    @Override
    public void tune() {
        System.out.println("Guitar is being tuned");
    }
}
