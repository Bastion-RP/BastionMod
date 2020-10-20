class brp_cassette_base extends ItemBase
{
    string SongToPlay()
    {
        return "BarbedWire_Deploy_loop_SoundSet"; // debug sound, if you hear this than you know something is wrong
    }
};
//4 noncopyright/royalty free songs below
class brp_cassette_alanwalkerfade extends brp_cassette_base
{
    override string SongToPlay()
    {
        return "coda_alanwalkerfade_SoundSet"; // name of soundset from above
    }
}

class brp_cassette_darkmusicfatallullaby extends brp_cassette_base
{
    override string SongToPlay()
    {
        return "coda_darkmusicfatallullaby_SoundSet"; // name of soundset from above
    }
}

class brp_cassette_onlypianoloneliness extends brp_cassette_base
{
    override string SongToPlay()
    {
        return "coda_onlypianoloneliness_SoundSet"; // name of soundset from above
    }
}

class brp_cassette_cartoonwhywelose extends brp_cassette_base
{
    override string SongToPlay()
    {
        return "coda_cartoonwhywelose_SoundSet"; // name of soundset from above
    }
}