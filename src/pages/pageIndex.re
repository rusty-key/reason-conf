open Util;

[@bs.module] external scriptLogo : string = "../assets/script18-logo.svg";

[@bs.module]
external reasonViennaLogo : string = "../assets/reasonvienna-logo.svg";

[@bs.module] external reactViennaLogo : string = "../assets/React-Vienna.svg";

[@bs.module] external agentLogo : string = "../assets/agent-logo.svg";

let component = ReasonReact.statelessComponent("Home");

module Tickets = Tito.Tickets;

module Link = Gatsby.Link;

let speakerColumn = (speaker: Data.Speaker.t) =>
  <li className="speaker-list--item" key=speaker.name>
    <Link to_=("/speakers/#" ++ Data.Speaker.speakerAnchor(speaker))>
      <SpeakerCard speaker />
    </Link>
  </li>;

let sponsorLogo = (sponsor: Partners.sponsorT) => {
  Js.log(sponsor);
  let className =
    switch (sponsor.tier) {
    | Gold => "partners--listItem_gold"
    | Catering => "partners--listItem_catering"
    | LocalSupport => "partners--listItem_local"
    | Partner => "partners--listItem_partner"
    };
  let title =
    switch (sponsor.tier) {
    | Gold => "Gold Sponsor"
    | Catering => "Food & Drinks"
    | LocalSupport => "Supporter"
    | Partner => "Partner"
    };
  <li className=("partners--listItem " ++ className) key=sponsor.name>
    <figure className="partners--figure">
      <a href=sponsor.href title=sponsor.name target="_blank">
        <img src=sponsor.logoUrl alt=sponsor.name className="partners--logo" />
      </a>
      <figcaption className="partners--caption"> (title |> s) </figcaption>
    </figure>
  </li>;
};

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <ParallaxScroll
        from="top-bottom"
        to_="bottom-top"
        props={
          "--header-ty": {
            "from": "100px",
            "to": "-100px",
          },
          "--header-clip": {
            "from": "10",
            "to": "4vw",
          },
        }>
        ...<header className="teaser">
             <section className="container_centered grid grid_6cols">
               <h1 className="teaser--logo">
                 <img
                   src=Assets.logo
                   alt="ReasonConf 2018"
                   className="teaser--image"
                 />
               </h1>
               <section className="teaser--navigation">
                 <Navigation pathName="/" />
               </section>
               <div className="teaser--meta">
                 <h2 className="teaser--dates">
                   <time dateTime="2018-05-11/2018-05-13">
                     ({j|11–13 May 2018|j} |> s)
                   </time>
                 </h2>
                 <p className="teaser--location"> ("Vienna, Austria" |> s) </p>
               </div>
               <p className="teaser--tagline">
                 (
                   {j|World’s first Reason conference for web-developers & OCaml enthusiasts|j}
                   |> s
                 )
               </p>
             </section>
           </header>
      </ParallaxScroll>
      <section className="offering">
        <div className="container_centered grid grid_6cols">
          <h2 className="offering--heading">
            ("Get productive with Reason in 3 days" |> s)
          </h2>
          <section className="offering--text">
            <p>
              (
                {js|
                  Reason is the next big thing and it is time to bring
                  the community together. Come and learn about the
                  language and get inspired for innovation.
                |js}
                |> s
              )
            </p>
            <p>
              (
                {js|
                  We want to motivate you to add Reason & OCaml to
                  your professional toolbelt and make you
                  feel comfortable in the ecosystem.
                |js}
                |> s
              )
            </p>
            <p>
              (
                {js|
                  This conference is aiming for a well-balanced schedule
                  with a practical, social and theoretical context.
                |js}
                |> s
              )
            </p>
          </section>
          <dl className="timeline">
            <dt className="timeline--date">
              <time dateTime="2018-05-11">
                ("11" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Friday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Day 1: Get started" |> s) </h3>
              <p>
                (
                  {js|
                    An optional workshop day to get every beginner and
                    intermediate attendee into the language &
                    platform.
                  |js}
                  |> s
                )
              </p>
            </dd>
            <dt className="timeline--date">
              <time dateTime="2018-05-12">
                ("12" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Saturday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Day 2: Get inspired" |> s) </h3>
              <p>
                (
                  {js|
                    This is the main conference day with lectures and talks.
                    Speakers of the Reason / OCaml community (with special guests
                    from the Reason & ReasonReact project) will inspire attendees for
                    more advanced topics.
                  |js}
                  |> s
                )
              </p>
            </dd>
            <dt className="timeline--date">
              <time dateTime="2018-05-13">
                ("13" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Sunday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Day 3: Get productive" |> s) </h3>
              <p>
                (
                  {js|
                    On the last day we encourage attendees to start
                    their first Reason projects, aided by our mentors,
                    speakers and volunteers. Alternatively for those
                    who want to relax, we offer a local-guided tour
                    through the beautiful city Vienna!
                  |js}
                  |> s
                )
              </p>
            </dd>
          </dl>
        </div>
      </section>
      <section className="speakers">
        <div className="container_centered">
          <h2> ("Speakers" |> s) </h2>
          <ParallaxScroll
            from="top-bottom"
            to_="bottom-top"
            props={
              "--speakers-ty": {
                "from": "100px",
                "to": "-100px",
              },
            }>
            ...<ul className="speaker-list">
                 (
                   Data.Speaker.speakers
                   |> Array.map(speakerColumn)
                   |> ReasonReact.array
                 )
               </ul>
          </ParallaxScroll>
        </div>
      </section>
      <section className="tickets">
        <div className="container_centered">
          <h2 id="tickets"> ("Tickets" |> s) </h2>
          <Tickets event="reason-conf/reason-conf-2018" />
          <p className="extraText">
            ("Tickets are not refundable, but re-assignable." |> s)
          </p>
          <p className="extraText">
            (
              "We also offer free tickets for underrepresented groups in tech. "
              |> s
            )
            <a
              href="https://diversitytickets.org/events/153/applications/new?"
              target="_blank">
              (s("Apply for a diversity ticket"))
            </a>
          </p>
        </div>
      </section>
      <section className="sponsors">
        <div className="container_centered">
          <h2> ("Sponsors & Partners" |> s) </h2>
          <p className="extraText">
            ("Do you want to help us make a better conference? " |> s)
            <Link to_="/sponsors"> ("Become a sponsor!" |> s) </Link>
          </p>
          <ul className="partners">
            (Partners.sponsors |> Array.map(sponsorLogo) |> ReasonReact.array)
          </ul>
          <ul className="partners">
            (Partners.partners |> Array.map(sponsorLogo) |> ReasonReact.array)
          </ul>
        </div>
      </section>
    </div>,
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
