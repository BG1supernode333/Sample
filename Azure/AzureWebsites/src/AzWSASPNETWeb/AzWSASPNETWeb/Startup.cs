using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(AzWSASPNETWeb.Startup))]
namespace AzWSASPNETWeb
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
