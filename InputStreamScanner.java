public class InputStreamScanner{
    public boolean setsd=false;
    public InputStream ins=null;
    public void Scan(InputStream ins){
        this.ins=ins;
        this.seted=true;
    }
    public byte[] Compile() throws IOException{
        byte[] rc=new byte[2048];
        int len=0;
        ByteArrayOutputStream bos=new ByteArrayOutputStream();
        while((len=this.ins.read(rc))!=-1){
            bos.write(rc,0,len);
        }
        bos.close();
        return bos.toByteArray();
    }
}
