namespace Stochastic {
        [Compact]
        [CCode (cheader_filename="../..StochasticLib/src/stochasticlib.h", cname="stochastic", cprefix="stochastic_")]
        class Simple {
                //  public Simple(string? server = null, string? name = null, Stream.Direction dir = Stream.Direction.PLAYBACK,
                //                  string? dev = null, string stream_name = "",
                //                  SampleSpec ss = SampleSpec(){ format = SampleFormat.S16NE, rate = 44100, channels = 2 },
                //                  ChannelMap? map = null, Stream.BufferAttr? attr = null, out int error = null);
                //  public int write(void* data, size_t bytes, out int error = null);
                //  public int drain(out int error = null);
                //  public int read(void* data, size_t bytes, out int error = null);
                //  public usec get_latency(out int error = null);
                //  public int flush(out int error = null);
                public int echo_number(int value);
        }
}