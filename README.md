# CSAW 2019 Pwny Racing Challenges 


Each year for [CSAW](https://ctf.csaw.io/), [Vector 35](https://vector35.com) tries to come up with their best CTF challenge ideas. This year we decided to work with [@Zetatwo](https://twitter.com/zetatwo) on his awesome [Pwny Racing](https://pwny.racing/) series.

What resulted was an [11 hour stream](https://www.youtube.com/watch?v=lYLbwayCzps) that saw a field of [ten teams](https://challonge.com/csaw_pwny_racing) whittled to one [top winner](https://ufsit.org/).

This repository has all of the challenges that were created for the event.

## Challenges

- [Storefront](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round1/storefront) A standard buffer overflow 
- [Repass](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round1/repass): Easy and fast
- [fourmatts](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round2/fourmatts): You're never gonna guess the challenge type from the name
- [gotcha](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round2/gotcha): Got overwrite. GET IT?!
- [kernel](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round2/kernel): No, not a kernel challenge. Just named that way for the lulz because Jazzy said we wouldn't have a kernel challenge in the event. ;-) 
- [multilingual](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round2/multilingual): Challenge with a twist
- [pttp](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round3/pttp): Contributed by [Alex Taylor](https://twitter.com/fuzyll)
- [roplcopter](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round3/roplcopter): ROP payload. Surprised?
- [confused](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round4/confused): The names really are starting to hint as to the bugs pretty clearly
- [murica](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/round4/murica): Winner of the "best pun in a flag" award. Yup, it's a use-after-freedom. 

## Streaming Setup

For our streaming setup, we had one dedicated capture laptop running two different capture cards ([1](https://www.elgato.com/en/gaming/game-capture-hd60-s),[2](https://www.magewell.com/products/usb-capture-hdmi-gen-2)) streaming via two separate [OBS](https://obsproject.com/) processes to a single [nginx proxy](https://docs.nginx.com/nginx/admin-guide/dynamic-modules/rtmp/). The master OBS stream let us mix the two feeds, adding in audio from two [samsun go](https://www.amazon.com/Samson-Mic-Portable-Condenser-Microphone/dp/B001R76D42) mics. 

The challenges were all hosted in a docker server provided by the event organizers including the custom [challenge server](https://github.com/Vector35/csaw-2019-pwny-race/tree/master/server).