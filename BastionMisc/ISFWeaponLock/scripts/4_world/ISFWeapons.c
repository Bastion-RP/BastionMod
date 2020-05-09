class Ck556_Base: FAL_Base {
    override bool IsISFWeapon() {
        return true;
    }
}

class CSP9_Base: CZ75_Base {
    override bool IsISFWeapon() {
        return true;
    }
}

class Csc45_Base : AKS74U {
    override bool IsISFWeapon() {
        return true;
    }
}

class BRP_CSR556 : Ck556_Base {}
class BRP_CSP9 : CSP9_Base {}
class BRP_CSC45 : Csc45_Base {}