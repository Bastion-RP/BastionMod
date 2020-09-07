class CSR556_Base : FAL_Base {
    override bool IsISFWeapon() {
        return true;
    }
}

class CSP9_Base : CZ75_Base {
    override bool IsISFWeapon() {
        return true;
    }
}

class Csc45_Base : AKS74U {
    override bool IsISFWeapon() {
        return true;
    }
}

class CSM762_Base : M4A1_Base {
    override bool IsISFWeapon() {
        return true;
    }
}

modded class BRP_Taser_Base {
    override bool IsISFWeapon() {
        return true;
    }
}

modded class BRP_CSSMG9_Base {
    override bool IsISFWeapon() {
        return true;
    }
}

modded class BRP_SCARH_Base {
    override bool IsISFWeapon() {
        return true;
    }
}

class BRP_CSM762_Black : CSM762_Base { }
class BRP_CSM762_Green : CSM762_Base { }
class BRP_CSM762_Tan : CSM762_Base { }
class BRP_CSR556 : CSR556_Base { }
class BRP_CSP9 : CSP9_Base { }
class BRP_CSC45 : Csc45_Base { }