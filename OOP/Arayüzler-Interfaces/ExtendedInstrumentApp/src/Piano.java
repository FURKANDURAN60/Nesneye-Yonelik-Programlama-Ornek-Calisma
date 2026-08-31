public class Piano implements Instrument, KeyboardInstrument{
    @Override
    public void play() {
        System.out.println("Piano is playing");
    }

    @Override
    public void press(){
        System.out.println("Piano key is pressed");
    }
}
